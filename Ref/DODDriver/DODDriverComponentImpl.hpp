// ======================================================================
// \title  DODDriverComponentImpl.hpp
// \author jzl0213
// \brief  hpp file for DODDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef DODDriver_HPP
#define DODDriver_HPP

#include "Ref/DODDriver/DODDriverComponentAc.hpp"

namespace Ref {

  class DODDriverComponentImpl //: public DODDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object DODDriver
      //!
      DODDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object DODDriver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object DODDriver
      //!
      ~DODDriverComponentImpl(void);
      
      private:
        F32 lastDOD;

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

      //! Handler implementation for managerReqIn
      //!
      void managerReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for DODDRIVER_TEST command handler
      //! 
      void DODDRIVER_TEST_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif
