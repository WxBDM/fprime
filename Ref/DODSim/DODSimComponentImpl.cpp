// ======================================================================
// \title  DODSimComponentImpl.cpp
// \author jzl0213
// \brief  cpp file for DODSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DODSim/DODSimComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DODSimComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DODSimComponentImpl(
        const char *const compName
    ) :
      DODSimComponentBase(compName)
#else
    DODSimComponentImpl(void)
#endif
  {

  }

  void DODSimComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DODSimComponentBase::init(queueDepth, instance);
  }

  DODSimComponentImpl ::
    ~DODSimComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DODSimComponentImpl ::
    driverReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->tempOut_out(0, this->currDOD);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void DODSimComponentImpl ::
    DODSIM_SET_DOD_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 depthOfDischarge
    )
  {
    this->currDOD = depthOfDischarge;
    this->tlmWrite_TEMPSIM_CURR_DOD(this->currDOD);
    this->log_ACTIVITY_HI_TEMPSIM_DOD_CHANGED(depthOfDischarge);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
