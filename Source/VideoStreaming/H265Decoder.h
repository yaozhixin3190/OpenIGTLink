/*=========================================================================
 
 Program:   H265Encoder
 Language:  C++
 
 Copyright (c) Insight Software Consortium. All rights reserved.
 
 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notices for more information.
 
 =========================================================================*/
#ifndef __igtlH265Decoder_h
#define __igtlH265Decoder_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
#include <limits.h>
#include <string.h>
#include <fstream>
#include "igtl_types.h"
#include "igtlVideoMessage.h"
#include "igtlCodecCommonClasses.h"

#include "gpac/modules/openhevc_dec/openHevcWrapper.h"

#define FRAME_CONCEALMENT   0

  class H265Decoder:public GenericDecoder
  {
  public: 
    H265Decoder();
    ~H265Decoder();
    
    typedef struct Info {
      int NbFrame;
      int Poc;
      int Tid;
      int Qid;
      int type;
      int size;
    } Info;
    
    virtual int DecodeBitStreamIntoFrame(unsigned char* bitStream,igtl_uint8* outputFrame, igtl_uint32 iDimensions[2], igtl_uint64 &iStreamSize);
    
    virtual int DecodeVideoMSGIntoSingleFrame(igtl::VideoMessage* videoMessage, SourcePicture* pDecodedPic);
  
  private:
    
    virtual void ComposeByteSteam(igtl_uint8** inputData, int dimension[2], int iStride[2], igtl_uint8 *outputFrame);
    
    int ReconstructFrame(OpenHevc_Frame_cpy *openHevcFrame,igtl_uint8* outputFrame);
    
    OpenHevc_Handle    openHevcHandle;
    
    OpenHevc_Frame_cpy     openHevcFrame;
    
    int nb_pthreads;
    
  };

#endif