// ======================================================================
// \title  DODSimComponentImpl.hpp
// \author jzl0213
// \brief  hpp file for DODSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DODSim_HPP
#define DODSim_HPP

#include "Ref/DODSim/DODSimComponentAc.hpp"

namespace Ref {

  class DODSimComponentImpl :
    public DODSimComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DODSim
      //!
      DODSimComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DODSim
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DODSim
      //!
      ~DODSimComponentImpl(void);

      private:
			  F32 currDOD = 50;
      
    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for driverReqIn
      //!
      void driverReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for DODSIM_SET_DOD command handler
      //! 
      void DODSIM_SET_DOD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 depthOfDischarge 
      );


    };

} // end namespace Ref

#endif
