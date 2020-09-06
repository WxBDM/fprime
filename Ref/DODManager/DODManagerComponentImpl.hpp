// ======================================================================
// \title  DODManagerComponentImpl.hpp
// \author jzl0213
// \brief  hpp file for DODManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DODManager_HPP
#define DODManager_HPP

#include "Ref/DODManager/DODManagerComponentAc.hpp"

namespace Ref {

  class DODManagerComponentImpl :
    public DODManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DODManager
      //!
      DODManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DODManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DODManager
      //!
      ~DODManagerComponentImpl(void);

      private:
        F32 lastDOD;
        bool autoCheckEnabled;

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

      //! Handler implementation for monitorDODReqIn
      //!
      void monitorDODReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for DOD_MANAGER_ENABLE_AUTO_CHECK command handler
      //! 
      void DOD_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for DOD_MANAGER_DISABLE_AUTO_CHECK command handler
      //! 
      void DOD_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
