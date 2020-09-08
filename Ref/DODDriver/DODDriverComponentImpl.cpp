// ======================================================================
// \title  DODDriverComponentImpl.cpp
// \author jzl0213
// \brief  cpp file for DODDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DODDriver/DODDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DODDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DODDriverComponentImpl(
        const char *const compName
    ) : DODDriverComponentBase(compName)
#else
    DODDriverComponentImpl(void)
#endif
  {
    this->lastDOD = 0;
    this->tlmWrite_DRIVER_LAST_DOD(0);
  }

  void DODDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DODDriverComponentBase::init(queueDepth, instance);
  }

  DODDriverComponentImpl ::
    ~DODDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DODDriverComponentImpl ::
    dodIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 depthOfDischarge
    )
  {
    this->lastDOD = depthOfDischarge;
    this->tlmWrite_DRIVER_LAST_DOD(depthOfDischarge);
    this->dodOut_out(0, this->lastDOD);
  }

  void DODDriverComponentImpl ::
    managerReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->driverReqOut_out(0, 1);
  }
  //bellow is possible shitty solution
    void DODDriverComponentImpl ::
    DODDRIVER_TEST_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      ) 
   {
   //todo
   }

  
  
} // end namespace Ref
