// ======================================================================
// \title  IMUDriverComponentImpl.cpp
// \author bdmolyne
// \brief  cpp file for IMUDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/IMUDriver/IMUDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  IMUDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    IMUDriverComponentImpl(
        const char *const compName
    ) :
      IMUDriverComponentBase(compName)
#else
    IMUDriverComponentImpl(void)
#endif
  {
      this -> last_x_axis = 0;
      this -> last_y_axis = 0;
      this -> last_z_axis = 0;
      
      this -> tlmWrite_DRIVER_LAST_ANG_VELOC(0);
  }

  void IMUDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    IMUDriverComponentBase::init(queueDepth, instance);
  }

  IMUDriverComponentImpl ::
    ~IMUDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void IMUDriverComponentImpl ::
    angularVelIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 x_axis,
        F32 y_axis,
        F32 z_axis
    )
  {
    // TODO
      this -> last_x_axis = x_axis;
      this -> last_y_axis = y_axis;
      this -> last_z_axis = z_axis;
      
      this -> tlmWrite_DRIVER_LAST_ANG_VELOC(x_axis);
      
      this -> angularVelOut_out(0, this->last_x_axis, this->last_y_axis, this->last_z_axis);
  }

  void IMUDriverComponentImpl ::
    managerReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request_x,
        F32 request_y,
        F32 request_z
    )
  {
    // TODO
      this->driverReqOut_out(0, 0, 0, 0);
  }

} // end namespace Ref
