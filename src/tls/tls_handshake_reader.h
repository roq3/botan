/*
* TLS Handshake Reader
* (C) 2012 Jack Lloyd
*
* Released under the terms of the Botan license
*/

#ifndef BOTAN_TLS_HANDSHAKE_READER_H__
#define BOTAN_TLS_HANDSHAKE_READER_H__

#include <botan/tls_magic.h>
#include <botan/secqueue.h>
#include <botan/loadstor.h>
#include <utility>

namespace Botan {

namespace TLS {

/**
* Handshake Reader Interface
*/
class Handshake_Reader
   {
   public:
      virtual void add_input(const byte record[], size_t record_size) = 0;

      virtual bool empty() const = 0;

      virtual bool have_full_record() const = 0;

      virtual std::pair<Handshake_Type, MemoryVector<byte> > get_next_record() = 0;

      virtual ~Handshake_Reader() {}
   };

/**
* Reader of TLS handshake messages
*/
class Stream_Handshake_Reader : public Handshake_Reader
   {
   public:
      void add_input(const byte record[], size_t record_size);

      bool empty() const;

      bool have_full_record() const;

      std::pair<Handshake_Type, MemoryVector<byte> > get_next_record();
   private:
      SecureQueue m_queue;
   };

}

}

#endif
