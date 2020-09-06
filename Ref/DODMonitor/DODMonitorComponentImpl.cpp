// ======================================================================
// \title  DODMonitorComponentImpl.cpp
// \author jzl0213
// \brief  cpp file for DODMonitor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/DODMonitor/DODMonitorComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DODMonitorComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DODMonitorComponentImpl(
        const char *const compName
    ) :
      DODMonitorComponentBase(compName)
#else
    DODMonitorComponentImpl(void)
#endif
  {
    this->lastDOD = 0;
    this->tlmWrite_MONITOR_LAST_DOD(this->lastDOD);
    this->critWarn = false;
  }

  void DODMonitorComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    DODMonitorComponentBase::init(queueDepth, instance);
  }

  DODMonitorComponentImpl ::
    ~DODMonitorComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DODMonitorComponentImpl ::
    dodIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->lastDOD = request;
    this->tlmWrite_MONITOR_LAST_DOD(this->lastDOD);
    int battery = this->currBattery;

    if(this->critWarn == false) {
      if(this->lastDOD < this->dodThresholds[battery][0]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_CRITICAL_LO(this->lastDOD);
        this->critWarn = true;
      }
      if(this->lastDOD > this->dodThresholds[battery][1]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_CRITICAL_HI(this->lastDOD);
        this->critWarn = true;
      }
    } else {
      if(this->lastDOD >= this->dodThresholds[battery][0] && this->lastDOD <= this->dodThresholds[battery][1]) {
        this->critWarn = false;
      }
    }
  }

  void DODMonitorComponentImpl ::
    batteryIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 nextBattery
    )
  {
    this->currBattery = nextBattery;
    this->tlmWrite_MONITOR_DOD_CURR_BATTERY(this->currBattery);
  }

  void DODMonitorComponentImpl ::
    threshIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 battery,
        F32 minDOD,
        F32 maxDOD
    )
  {
    int batteryInt = battery;
    this->dodThresholds[batteryInt][0] = minDOD;
    this->dodThresholds[batteryInt][1] = maxDOD;
    this->log_ACTIVITY_HI_HEALTH_MONITOR_THRESHOLD_CHANGED(battery, minDOD, maxDOD);
  }

  void DODMonitorComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->monitorDODReqOut_out(0, 1);
  }

} // end namespace Ref
