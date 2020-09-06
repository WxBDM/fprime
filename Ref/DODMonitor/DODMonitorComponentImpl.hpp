// ======================================================================
// \title  DODMonitorComponentImpl.hpp
// \author jzl0213
// \brief  hpp file for DODMonitor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DODMonitor_HPP
#define DODMonitor_HPP

#include "Ref/DODMonitor/DODMonitorComponentAc.hpp"

namespace Ref {

  class DODMonitorComponentImpl :
    public DODMonitorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DODMonitor
      //!
      DODMonitorComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DODMonitor
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DODMonitor
      //!
      ~DODMonitorComponentImpl(void);

      private:
        bool critWarn;
        F32 lastDOD;
        F32 currBattery;
        // {BackOfTheSpace, CartSack, EPS, 
        //  body1, body2
        //  DOD range can be changed later
        F32 dodThresholds[5][2] = {{50, 100}, {30, 80}, {20, 80}, 
                                    {0, 100}, {0, 100}};

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for dodIn
      //!
      void dodIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 depthOfDischarge 
      );

      //! Handler implementation for batteryIn
      //!
      void batteryIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 nextBattery 
      );

      //! Handler implementation for threshIn
      //!
      void threshIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 battery, 
          F32 minDOD, 
          F32 maxDOD 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );


    };

} // end namespace Ref

#endif
