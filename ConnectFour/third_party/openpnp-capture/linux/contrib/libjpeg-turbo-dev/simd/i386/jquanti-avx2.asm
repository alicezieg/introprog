;
; jquanti.asm - sample quantization (AVX2)
;
; Copyright 2009 Pierre Ossman <ossman@cendio.se> for Cendio AB
; Copyright (C) 2016, D. R. Commander.
; Copyright (C) 2016, Matthieu Darbois.
;
; Based on the x86 SIMD extension for IJG JPEG library
; Copyright (C) 1999-2006, MIYASAKA Masaru.
; For conditions of distribution and use, see copyright notice in jsimdext.inc
;
; This file should be assembled with NASM (Netwide Assembler),
; can *not* be assembled with Microsoft's MASM or any compatible
; assembler (including Borland's Turbo Assembler).
; NASM is available from http://nasm.sourceforge.net/ or
; http://sourceforge.net/project/showfiles.php?group_id=6208
;
; [TAB8]

%include "jsimdext.inc"
%include "jdct.inc"

; --------------------------------------------------------------------------
    SECTION     SEG_TEXT
    BITS        32

; --------------------------------------------------------------------------
;
; Quantize/descale the coefficients, and store into coef_block
;
; This implementation is based on an algorithm described in
;   "How to optimize for the Pentium family of microprocessors"
;   (http://www.agner.org/assem/).
;
; GLOBAL(void)
; jsimd_quantize_avx2 (JCOEFPTR coef_block, DCTELEM *divisors,
;                      DCTELEM *workspace);
;

%define RECIPROCAL(m,n,b)  XMMBLOCK(DCTSIZE*0+(m),(n),(b),SIZEOF_DCTELEM)
%define CORRECTION(m,n,b)  XMMBLOCK(DCTSIZE*1+(m),(n),(b),SIZEOF_DCTELEM)
%define SCALE(m,n,b)       XMMBLOCK(DCTSIZE*2+(m),(n),(b),SIZEOF_DCTELEM)

%define coef_block  ebp+8               ; JCOEFPTR coef_block
%define divisors    ebp+12              ; DCTELEM *divisors
%define workspace   ebp+16              ; DCTELEM *workspace

    align       32
    global      EXTN(jsimd_quantize_avx2)

EXTN(jsimd_quantize_avx2):
    push        ebp
    mov         ebp, esp
;   push        ebx                     ; unused
;   push        ecx                     ; unused
;   push        edx                     ; need not be preserved
    push        esi
    push        edi

    mov         esi, POINTER [workspace]
    mov         edx, POINTER [divisors]
    mov         edi, JCOEFPTR [coef_block]

    vmovdqu     ymm4, [XMMBLOCK(0,0,esi,SIZEOF_DCTELEM)]
    vmovdqu     ymm5, [XMMBLOCK(2,0,esi,SIZEOF_DCTELEM)]
    vmovdqu     ymm6, [XMMBLOCK(4,0,esi,SIZEOF_DCTELEM)]
    vmovdqu     ymm7, [XMMBLOCK(6,0,esi,SIZEOF_DCTELEM)]
    vpabsw      ymm0, ymm4
    vpabsw      ymm1, ymm5
    vpabsw      ymm2, ymm6
    vpabsw      ymm3, ymm7

    vpaddw      ymm0, YMMWORD [CORRECTION(0,0,edx)]  ; correction + roundfactor
    vpaddw      ymm1, YMMWORD [CORRECTION(2,0,edx)]
    vpaddw      ymm2, YMMWORD [CORRECTION(4,0,edx)]
    vpaddw      ymm3, YMMWORD [CORRECTION(6,0,edx)]
    vpmulhuw    ymm0, YMMWORD [RECIPROCAL(0,0,edx)]  ; reciprocal
    vpmulhuw    ymm1, YMMWORD [RECIPROCAL(2,0,edx)]
    vpmulhuw    ymm2, YMMWORD [RECIPROCAL(4,0,edx)]
    vpmulhuw    ymm3, YMMWORD [RECIPROCAL(6,0,edx)]
    vpmulhuw    ymm0, YMMWORD [SCALE(0,0,edx)]       ; scale
    vpmulhuw    ymm1, YMMWORD [SCALE(2,0,edx)]
    vpmulhuw    ymm2, YMMWORD [SCALE(4,0,edx)]
    vpmulhuw    ymm3, YMMWORD [SCALE(6,0,edx)]

    vpsignw     ymm0, ymm0, ymm4
    vpsignw     ymm1, ymm1, ymm5
    vpsignw     ymm2, ymm2, ymm6
    vpsignw     ymm3, ymm3, ymm7

    vmovdqu     [XMMBLOCK(0,0,edi,SIZEOF_DCTELEM)], ymm0
    vmovdqu     [XMMBLOCK(2,0,edi,SIZEOF_DCTELEM)], ymm1
    vmovdqu     [XMMBLOCK(4,0,edi,SIZEOF_DCTELEM)], ymm2
    vmovdqu     [XMMBLOCK(6,0,edi,SIZEOF_DCTELEM)], ymm3

    vzeroupper
    pop         edi
    pop         esi
;   pop         edx                     ; need not be preserved
;   pop         ecx                     ; unused
;   pop         ebx                     ; unused
    pop         ebp
    ret

; For some reason, the OS X linker does not honor the request to align the
; segment unless we do this.
    align       32
