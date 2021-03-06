/*=========================================================================
 
 Program:   VPXEncoder
 Language:  C++
 
 Copyright (c) Insight Software Consortium. All rights reserved.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notices for more information.
 
 =========================================================================*/

#ifndef __igtlVP9Decoder_h
#define __igtlVP9Decoder_h

#include <time.h>
#if defined(_WIN32) /*&& defined(_DEBUG)*/
  #include <windows.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <sys/types.h>
#else
  #include <sys/time.h>
#endif

#include <vector>
#include <limits.h>
#include <string.h>
#include "igtl_types.h"
#include "igtlVideoMessage.h"
#include "igtlCodecCommonClasses.h"
#include "vpx/vpx_decoder.h"
#include "tools_common.h"
#include "video_reader.h"
#include "vpx_config.h"

#define NO_DELAY_DECODING
class VP9Decoder:public GenericDecoder
{
public: 
  VP9Decoder();
  ~VP9Decoder();
  
  virtual int DecodeBitStreamIntoFrame(unsigned char* bitStream,igtl_uint8* outputFrame, igtl_uint32 iDimensions[2], igtl_uint64 &iStreamSize);
  
  virtual int DecodeVideoMSGIntoSingleFrame(igtl::VideoMessage* videoMessage, SourcePicture* pDecodedPic);
  
private:
  virtual void ComposeByteSteam(igtl_uint8** inputData, int dimension[2], int iStride[2], igtl_uint8 *outputFrame);
  
  const VpxInterface* decoder;
  
  vpx_codec_ctx_t codec;
  
  vpx_image_t* outputImage;
  
  vpx_codec_iter_t iter;
  
};

#endif