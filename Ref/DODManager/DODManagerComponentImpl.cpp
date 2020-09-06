// ======================================================================
// \title  DODManagerComponentImpl.cpp
// \author jzl0213
// \brief  cpp file for DODManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DODManager/DODManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DODManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DODManagerComponentImpl(
        const char *const compName
    ) :
      DODManagerComponentBase(compName)
#else
    DODManagerComponentImpl(void)
#endif
  {
    this->lastDOD = 50;
    this->autoCheckEnabled = true;
    this->tlmWrite_DOD_MANAGER_LAST_DOD(50);
  }

  void DODManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DODManagerComponentBase::init(queueDepth, instance);
  }

  DODManagerComponentImpl ::
    ~DODManagerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DODManagerComponentImpl ::
    dodIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 depthOfDischarge
    )
  {
    this->lastDOD = depthOfDischarge;
    this->tlmWrite_DOD_MANAGER_LAST_DOD(depthOfDischarge);
  }

  void DODManagerComponentImpl ::
    monitorDODReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    //this->dodOut_out(0, this->lastDOD);
  }

  void DODManagerComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(this->autoCheckEnabled == true) {
      this->managerReqOut_out(0, 1);
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DODManagerComponentImpl ::
    DOD_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->autoCheckEnabled = true;
    this->log_ACTIVITY_LO_DOD_MANAGER_AUTOCHECK_ENABLED(1);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void DODManagerComponentImpl ::
    DOD_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->autoCheckEnabled = false;
    this->log_ACTIVITY_LO_DOD_MANAGER_AUTOCHECK_DISABLED(0);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
