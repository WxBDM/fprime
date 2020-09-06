// ======================================================================
// \title  IMUDriverComponentImpl.hpp
// \author bdmolyne
// \brief  hpp file for IMUDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef IMUDriver_HPP
#define IMUDriver_HPP

#include "Ref/IMUDriver/IMUDriverComponentAc.hpp"

namespace Ref {

  class IMUDriverComponentImpl :
    public IMUDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object IMUDriver
      //!
      IMUDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object IMUDriver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object IMUDriver
      //!
      ~IMUDriverComponentImpl(void);
    private:
      F32 last_x_axis = 0.2;
      F32 last_y_axis = 0.2;
      F32 last_z_axis = 0.2;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for angularVelIn
      //!
      void angularVelIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 x_axis, 
          F32 y_axis, 
          F32 z_axis 
      );

      //! Handler implementation for managerReqIn
      //!
      void managerReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request_x, 
          F32 request_y, 
          F32 request_z 
      );


    };

} // end namespace Ref

#endif
