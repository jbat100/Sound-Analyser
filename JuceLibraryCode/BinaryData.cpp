/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== CHANGELOG ==================
static const unsigned char temp_binary_data_0[] =
"1.3.0 2012-07-18\n"
"  removed non-standard malloc.h from kiss_fft.h\n"
"\n"
"  moved -lm to end of link line\n"
"\n"
"  checked various return values\n"
"\n"
"  converted python Numeric code to NumPy\n"
" \n"
"  fixed test of int32_t on 64 bit OS\n"
"\n"
"  added padding in a couple of places to allow SIMD alignment of structs\n"
"\n"
"1.2.9 2010-05-27\n"
"  threadsafe ( including OpenMP )\n"
"\n"
"  first edition of kissfft.hh the C++ template fft engine\n"
" \n"
"1.2.8 \n"
"  Changed memory.h to string.h -- apparently more standard\n"
"  \n"
"  Added openmp extensions.  This can have fairly linear speedups for larger FFT sizes.\n"
"\n"
"1.2.7 \n"
"  Shrank the real-fft memory footprint. Thanks to Galen Seitz.\n"
"\n"
"1.2.6 (Nov 14, 2006) The \"thanks to GenArts\" release.\n"
"  Added multi-dimensional real-optimized FFT, see tools/kiss_fftndr\n"
"  Thanks go to GenArts, Inc. for sponsoring the development.\n"
"\n"
"1.2.5 (June 27, 2006) The \"release for no good reason\" release.\n"
"   Changed some harmless code to make some compilers' warnings go away.\n"
"   Added some more digits to pi -- why not.\n"
"   Added kiss_fft_next_fast_size() function to help people decide how much to pad.\n"
"   Changed multidimensional test from 8 dimensions to only 3 to avoid testing \n"
"   problems with fixed point (sorry Buckaroo Banzai).\n"
"\n"
"1.2.4 (Oct 27, 2005)   The \"oops, inverse fixed point real fft was borked\" release. \n"
"   Fixed scaling bug for inverse fixed point real fft -- also fixed test code that should've been failing.\n"
"    Thanks to Jean-Marc Valin for bug report.\n"
"\n"
"   Use sys/types.h for more portable types than short,int,long => int16_t,int32_t,int64_t\n"
"   If your system does not have these, you may need to define them -- but at least it breaks in a \n"
"   loud and easily fixable way -- unlike silently using the wrong size type.\n"
"\n"
"   Hopefully tools/psdpng.c is fixed -- thanks to Steve Kellog for pointing out the weirdness.\n"
"\n"
"1.2.3 (June 25, 2005)   The \"you want to use WHAT as a sample\" release.\n"
"    Added ability to use 32 bit fixed point samples -- requires a 64 bit intermediate result, a la 'long long'\n"
"\n"
"    Added ability to do 4 FFTs in parallel by using SSE SIMD instructions. This is accomplished by\n"
"    using the __m128 (vector of 4 floats) as kiss_fft_scalar.  Define USE_SIMD to use this.\n"
"    \n"
"    I know, I know ...  this is drifting a bit from the \"kiss\" principle, but the speed advantages \n"
"    make it worth it for some.  Also recent gcc makes it SOO easy to use vectors of 4 floats like a POD type.\n"
"\n"
"1.2.2 (May 6, 2005)   The Matthew release\n"
"    Replaced fixed point division with multiply&shift.  Thanks to Jean-Marc Valin for \n"
"    discussions regarding.  Considerable speedup for fixed-point.\n"
"\n"
"    Corrected overflow protection in real fft routines  when using fixed point.\n"
"    Finder's Credit goes to Robert Oschler of robodance for pointing me at the bug.\n"
"    This also led to the CHECK_OVERFLOW_OP macro.\n"
"\n"
"1.2.1 (April 4, 2004) \n"
"    compiles cleanly with just about every -W warning flag under the sun\n"
"\n"
"    reorganized kiss_fft_state so it could be read-only/const. This may be useful for embedded systems\n"
"    that are willing to predeclare twiddle factors, factorization.\n"
"\n"
"    Fixed C_MUL,S_MUL on 16-bit platforms.\n"
"\n"
"    tmpbuf will only be allocated if input & output buffers are same\n"
"    scratchbuf will only be allocated for ffts that are not multiples of 2,3,5\n"
" \n"
"    NOTE: The tmpbuf,scratchbuf changes may require synchronization code for multi-threaded apps.\n"
"\n"
"\n"
"1.2 (Feb 23, 2004)\n"
"    interface change -- cfg object is forward declaration of struct instead of void*\n"
"    This maintains type saftey and lets the compiler warn/error about stupid mistakes.\n"
"            (prompted by suggestion from Erik de Castro Lopo)\n"
"\n"
"    small speed improvements\n"
"\n"
"    added psdpng.c -- sample utility that will create png spectrum \"waterfalls\" from an input file\n"
"        ( not terribly useful yet)\n"
"\n"
"1.1.1 (Feb 1, 2004 )\n"
"    minor bug fix -- only affects odd rank, in-place, multi-dimensional FFTs\n"
"\n"
"1.1 : (Jan 30,2004)\n"
"    split sample_code/ into test/ and tools/\n"
"\n"
"    Removed 2-D fft and added N-D fft (arbitrary)\n"
"\n"
"    modified fftutil.c to allow multi-d FFTs\n"
"\n"
"    Modified core fft routine to allow an input stride via kiss_fft_stride()\n"
"    (eased support of multi-D ffts)\n"
"\n"
"    Added fast convolution filtering (FIR filtering using overlap-scrap method, with tail scrap)\n"
"\n"
"    Add kfc.[ch]: the KISS FFT Cache. It takes care of allocs for you ( suggested by Oscar Lesta ).\n"
"\n"
"1.0.1 (Dec 15, 2003)\n"
"    fixed bug that occurred when nfft==1. Thanks to Steven Johnson.\n"
"    \n"
"1.0 : (Dec 14, 2003)\n"
"    changed kiss_fft function from using a single buffer, to two buffers.\n"
"    If the same buffer pointer is supplied for both in and out, kiss will\n"
"    manage the buffer copies.\n"
"\n"
"    added kiss_fft2d and kiss_fftr as separate source files (declarations in kiss_fft.h )\n"
"\n"
"0.4 :(Nov 4,2003) optimized for radix 2,3,4,5\n"
"\n"
"0.3 :(Oct 28, 2003) woops, version 2 didn't actually factor out any radices other than 2.\n"
"        Thanks to Steven Johnson for finding this one.\n"
"\n"
"0.2 :(Oct 27, 2003) added mixed radix, only radix 2,4 optimized versions\n"
"\n"
"0.1 :(May 19 2003)  initial release, radix 2 only\n";

const char* CHANGELOG = (const char*) temp_binary_data_0;

//================== COPYING ==================
static const unsigned char temp_binary_data_1[] =
"Copyright (c) 2003-2010 Mark Borgerding\n"
"\n"
"All rights reserved.\n"
"\n"
"Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:\n"
"\n"
"    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.\n"
"    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.\n"
"    * Neither the author nor the names of any contributors may be used to endorse or promote products derived from this software without specific prior written permission.\n"
"\n"
"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO E"
"VENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR"
" BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D"
"AMAGE.\n";

const char* COPYING = (const char*) temp_binary_data_1;

//================== README ==================
static const unsigned char temp_binary_data_2[] =
"KISS FFT - A mixed-radix Fast Fourier Transform based up on the principle, \n"
"\"Keep It Simple, Stupid.\"\n"
"\n"
"    There are many great fft libraries already around.  Kiss FFT is not trying\n"
"to be better than any of them.  It only attempts to be a reasonably efficient, \n"
"moderately useful FFT that can use fixed or floating data types and can be \n"
"incorporated into someone's C program in a few minutes with trivial licensing.\n"
"\n"
"USAGE:\n"
"\n"
"    The basic usage for 1-d complex FFT is:\n"
"\n"
"        #include \"kiss_fft.h\"\n"
"\n"
"        kiss_fft_cfg cfg = kiss_fft_alloc( nfft ,is_inverse_fft ,0,0 );\n"
"\n"
"        while ...\n"
"        \n"
"            ... // put kth sample in cx_in[k].r and cx_in[k].i\n"
"            \n"
"            kiss_fft( cfg , cx_in , cx_out );\n"
"            \n"
"            ... // transformed. DC is in cx_out[0].r and cx_out[0].i \n"
"            \n"
"        free(cfg);\n"
"\n"
"    Note: frequency-domain data is stored from dc up to 2pi.\n"
"    so cx_out[0] is the dc bin of the FFT\n"
"    and cx_out[nfft/2] is the Nyquist bin (if exists)\n"
"\n"
"    Declarations are in \"kiss_fft.h\", along with a brief description of the \n"
"functions you'll need to use. \n"
"\n"
"Code definitions for 1d complex FFTs are in kiss_fft.c.\n"
"\n"
"You can do other cool stuff with the extras you'll find in tools/\n"
"\n"
"    * multi-dimensional FFTs \n"
"    * real-optimized FFTs  (returns the positive half-spectrum: (nfft/2+1) complex frequency bins)\n"
"    * fast convolution FIR filtering (not available for fixed point)\n"
"    * spectrum image creation\n"
"\n"
"The core fft and most tools/ code can be compiled to use float, double,\n"
" Q15 short or Q31 samples. The default is float.\n"
"\n"
"\n"
"BACKGROUND:\n"
"\n"
"    I started coding this because I couldn't find a fixed point FFT that didn't \n"
"use assembly code.  I started with floating point numbers so I could get the \n"
"theory straight before working on fixed point issues.  In the end, I had a \n"
"little bit of code that could be recompiled easily to do ffts with short, float\n"
"or double (other types should be easy too).  \n"
"\n"
"    Once I got my FFT working, I was curious about the speed compared to\n"
"a well respected and highly optimized fft library.  I don't want to criticize \n"
"this great library, so let's call it FFT_BRANDX.\n"
"During this process, I learned:\n"
"\n"
"    1. FFT_BRANDX has more than 100K lines of code. The core of kiss_fft is about 500 lines (cpx 1-d).\n"
"    2. It took me an embarrassingly long time to get FFT_BRANDX working.\n"
"    3. A simple program using FFT_BRANDX is 522KB. A similar program using kiss_fft is 18KB (without optimizing for size).\n"
"    4. FFT_BRANDX is roughly twice as fast as KISS FFT in default mode.\n"
"\n"
"    It is wonderful that free, highly optimized libraries like FFT_BRANDX exist.\n"
"But such libraries carry a huge burden of complexity necessary to extract every \n"
"last bit of performance.\n"
"\n"
"    Sometimes simpler is better, even if it's not better.\n"
"\n"
"FREQUENTLY ASKED QUESTIONS:\n"
"\tQ: Can I use kissfft in a project with a ___ license?\n"
"\tA: Yes.  See LICENSE below.\n"
"\n"
"\tQ: Why don't I get the output I expect?\n"
"\tA: The two most common causes of this are \n"
"\t\t1) scaling : is there a constant multiplier between what you got and what you want?\n"
"\t\t2) mixed build environment -- all code must be compiled with same preprocessor \n"
"\t\tdefinitions for FIXED_POINT and kiss_fft_scalar\n"
"\n"
"\tQ: Will you write/debug my code for me?\n"
"\tA: Probably not unless you pay me.  I am happy to answer pointed and topical questions, but \n"
"\tI may refer you to a book, a forum, or some other resource.\n"
"\n"
"\n"
"PERFORMANCE:\n"
"    (on Athlon XP 2100+, with gcc 2.96, float data type)\n"
"\n"
"    Kiss performed 10000 1024-pt cpx ffts in .63 s of cpu time.\n"
"    For comparison, it took md5sum twice as long to process the same amount of data.\n"
"\n"
"    Transforming 5 minutes of CD quality audio takes less than a second (nfft=1024). \n"
"\n"
"DO NOT:\n"
"    ... use Kiss if you need the Fastest Fourier Transform in the World\n"
"    ... ask me to add features that will bloat the code\n"
"\n"
"UNDER THE HOOD:\n"
"\n"
"    Kiss FFT uses a time decimation, mixed-radix, out-of-place FFT. If you give it an input buffer  \n"
"    and output buffer that are the same, a temporary buffer will be created to hold the data.\n"
"\n"
"    No static data is used.  The core routines of kiss_fft are thread-safe (but not all of the tools directory).\n"
"\n"
"    No scaling is done for the floating point version (for speed).  \n"
"    Scaling is done both ways for the fixed-point version (for overflow prevention).\n"
"\n"
"    Optimized butterflies are used for factors 2,3,4, and 5. \n"
"\n"
"    The real (i.e. not complex) optimization code only works for even length ffts.  It does two half-length\n"
"    FFTs in parallel (packed into real&imag), and then combines them via twiddling.  The result is \n"
"    nfft/2+1 complex frequency bins from DC to Nyquist.  If you don't know what this means, search the web.\n"
"\n"
"    The fast convolution filtering uses the overlap-scrap method, slightly \n"
"    modified to put the scrap at the tail.\n"
"\n"
"LICENSE:\n"
"    Revised BSD License, see COPYING for verbiage. \n"
"    Basically, \"free to use&change, give credit where due, no guarantees\"\n"
"    Note this license is compatible with GPL at one end of the spectrum and closed, commercial software at \n"
"    the other end.  See http://www.fsf.org/licensing/licenses\n"
"\n"
"    A commercial license is available which removes the requirement for attribution.  Contact me for details.\n"
"\n"
"  \n"
"TODO:\n"
"    *) Add real optimization for odd length FFTs \n"
"    *) Document/revisit the input/output fft scaling\n"
"    *) Make doc describing the overlap (tail) scrap fast convolution filtering in kiss_fastfir.c\n"
"    *) Test all the ./tools/ code with fixed point (kiss_fastfir.c doesn't work, maybe others)\n"
"\n"
"AUTHOR:\n"
"    Mark Borgerding\n"
"    Mark@Borgerding.net\n";

const char* README = (const char*) temp_binary_data_2;

//================== README.simd ==================
static const unsigned char temp_binary_data_3[] =
"If you are reading this, it means you think you may be interested in using the SIMD extensions in kissfft \n"
"to do 4 *separate* FFTs at once.\n"
"\n"
"Beware! Beyond here there be dragons!\n"
"\n"
"This API is not easy to use, is not well documented, and breaks the KISS principle.  \n"
"\n"
"\n"
"Still reading? Okay, you may get rewarded for your patience with a considerable speedup \n"
"(2-3x) on intel x86 machines with SSE if you are willing to jump through some hoops.\n"
"\n"
"The basic idea is to use the packed 4 float __m128 data type as a scalar element.  \n"
"This means that the format is pretty convoluted. It performs 4 FFTs per fft call on signals A,B,C,D.\n"
"\n"
"For complex data, the data is interlaced as follows:\n"
"rA0,rB0,rC0,rD0,      iA0,iB0,iC0,iD0,   rA1,rB1,rC1,rD1, iA1,iB1,iC1,iD1 ...\n"
"where \"rA0\" is the real part of the zeroth sample for signal A\n"
"\n"
"Real-only data is laid out:\n"
"rA0,rB0,rC0,rD0,     rA1,rB1,rC1,rD1,      ... \n"
"\n"
"Compile with gcc flags something like\n"
"-O3 -mpreferred-stack-boundary=4  -DUSE_SIMD=1 -msse \n"
"\n"
"Be aware of SIMD alignment.  This is the most likely cause of segfaults.  \n"
"The code within kissfft uses scratch variables on the stack.  \n"
"With SIMD, these must have addresses on 16 byte boundaries.  \n"
"Search on \"SIMD alignment\" for more info.\n"
"\n"
"\n"
"\n"
"Robin at Divide Concept was kind enough to share his code for formatting to/from the SIMD kissfft.  \n"
"I have not run it -- use it at your own risk.  It appears to do 4xN and Nx4 transpositions \n"
"(out of place).\n"
"\n"
"void SSETools::pack128(float* target, float* source, unsigned long size128)\n"
"{\n"
"   __m128* pDest = (__m128*)target;\n"
"   __m128* pDestEnd = pDest+size128;\n"
"   float* source0=source;\n"
"   float* source1=source0+size128;\n"
"   float* source2=source1+size128;\n"
"   float* source3=source2+size128;\n"
"\n"
"   while(pDest<pDestEnd)\n"
"   {\n"
"       *pDest=_mm_set_ps(*source3,*source2,*source1,*source0);\n"
"       source0++;\n"
"       source1++;\n"
"       source2++;\n"
"       source3++;\n"
"       pDest++;\n"
"   }\n"
"}\n"
"\n"
"void SSETools::unpack128(float* target, float* source, unsigned long size128)\n"
"{\n"
"\n"
"   float* pSrc = source;\n"
"   float* pSrcEnd = pSrc+size128*4;\n"
"   float* target0=target;\n"
"   float* target1=target0+size128;\n"
"   float* target2=target1+size128;\n"
"   float* target3=target2+size128;\n"
"\n"
"   while(pSrc<pSrcEnd)\n"
"   {\n"
"       *target0=pSrc[0];\n"
"       *target1=pSrc[1];\n"
"       *target2=pSrc[2];\n"
"       *target3=pSrc[3];\n"
"       target0++;\n"
"       target1++;\n"
"       target2++;\n"
"       target3++;\n"
"       pSrc+=4;\n"
"   }\n"
"} \n";

const char* README_simd = (const char*) temp_binary_data_3;

//================== TIPS ==================
static const unsigned char temp_binary_data_4[] =
"Speed:\n"
"    * If you want to use multiple cores, then compile with -openmp or -fopenmp (see your compiler docs).\n"
"\tRealize that larger FFTs will reap more benefit than smaller FFTs. This generally uses more CPU time, but\n"
"\tless wall time.\n"
"\n"
"    * experiment with compiler flags\n"
"        Special thanks to Oscar Lesta. He suggested some compiler flags \n"
"        for gcc that make a big difference. They shave 10-15% off\n"
"        execution time on some systems.  Try some combination of:\n"
"                -march=pentiumpro\n"
"                -ffast-math\n"
"                -fomit-frame-pointer\n"
"\n"
"    * If the input data has no imaginary component, use the kiss_fftr code under tools/.\n"
"      Real ffts are roughly twice as fast as complex.\n"
"\n"
"    * If you can rearrange your code to do 4 FFTs in parallel and you are on a recent Intel or AMD machine,\n"
"    then you might want to experiment with the USE_SIMD code.  See README.simd\n"
"\n"
"\n"
"Reducing code size:\n"
"    * remove some of the butterflies. There are currently butterflies optimized for radices\n"
"        2,3,4,5.  It is worth mentioning that you can still use FFT sizes that contain \n"
"        other factors, they just won't be quite as fast.  You can decide for yourself \n"
"        whether to keep radix 2 or 4.  If you do some work in this area, let me \n"
"        know what you find.\n"
"\n"
"    * For platforms where ROM/code space is more plentiful than RAM,\n"
"     consider creating a hardcoded kiss_fft_state. In other words, decide which \n"
"     FFT size(s) you want and make a structure with the correct factors and twiddles.\n"
"\n"
"    * Frank van der Hulst offered numerous suggestions for smaller code size and correct operation \n"
"    on embedded targets.  \"I'm happy to help anyone who is trying to implement KISSFFT on a micro\"\n"
"\n"
"    Some of these were rolled into the mainline code base:\n"
"        - using long casts to promote intermediate results of short*short multiplication\n"
"        - delaying allocation of buffers that are sometimes unused.\n"
"    In some cases, it may be desirable to limit capability in order to better suit the target:\n"
"        - predefining the twiddle tables for the desired fft size.  \n";

const char* TIPS = (const char*) temp_binary_data_4;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xfcd5c174:  numBytes = 5070; return CHANGELOG;
        case 0x63a1442d:  numBytes = 1475; return COPYING;
        case 0x8fd84dae:  numBytes = 5627; return README;
        case 0x2aaba65e:  numBytes = 2419; return README_simd;
        case 0x00274b38:  numBytes = 2126; return TIPS;
        default: break;
    }

    numBytes = 0;
    return 0;
}

}
