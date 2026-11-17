/**
 * @file hash.h
 * @brief Hashing functions for hash tables and hash sets for LaMancha Engine
 * @author Alonso Moreno <ph0nsy>
 * @date 2026
 * @copyright Copyright (C) 2026 Alonso Moreno
 *
 */

#pragma once
#include <stdio.h>

namespace LaMancha
{
  namespace Utils
  {

    /**
    * @brief Byte wise FNV-1a (Fowler-Noll-Vo) over sizeof(T) bytes
    * @tparam T Type of whatever to hash
    * @param _val The variable to hash itself
    * @note Structs with padding may hash inconsistently if padding bytes are uninitialized
    */
    template <typename T>
    size_t hash(const T& _val) 
    {
      const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&_val);
      size_t hsh = 14695981039346656037ULL; // FNV offset basis
      for (size_t i = 0; i < sizeof(T); i++) {
        hsh ^= bytes[i];
        hsh *= 1099511628211ULL; // FNV prime
      }
      return hsh;
    }

    template <typename T>
    size_t hash(const T& _val, const size_t _len)
    {
      const uint8_t* bytes = reinterpret_cast<const uint8_t*>(&_val);
      size_t hsh = 14695981039346656037ULL; // FNV offset basis
      for (size_t i = 0; i < _len; i++) {
        hsh ^= bytes[i];
        hsh *= 1099511628211ULL; // FNV prime
      }
      return hsh;
    }

    /**
    * @brief Fast specialization for 32 bits-sized types (handles, IDs)
    * @param _val The variable to hash itself
    * @note For Handle / ID types padding is never an issue since they are plain integers.
    * @see https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
    */
    template<>
    size_t hash(const uint32_t& _val) 
    {
      size_t hsh = _val;
      hsh ^= hsh >> 16;
      hsh *= 0x45d9f3b;
      hsh ^= hsh >> 16;
      return hsh;
    }

    /**
    * @brief Fast specialization for 64 bits-sized types (handles, IDs)
    * @param _val The variable to hash itself
    * @note For Handle / ID types padding is never an issue since they are plain integers.
    * @see https://www.reddit.com/r/C_Programming/comments/1ntrhhh/making_fast_generic_hash_table/
    */
    template<>
    size_t hash(const uint64_t& _val) 
    {
      size_t hsh = _val;
      hsh ^= hsh >> 30;
      hsh *= 0xbf58476d1ce4e5b9ULL;
      hsh ^= hsh >> 27;
      hsh *= 0x94d049bb133111ebULL;
      hsh ^= hsh >> 31;
      return hsh;
    }

    uint8_t getEncodedH2(size_t hash)
    {
      uint8_t h2 = hash & 0x7F;
      return h2 == 0 ? 1 : h2; // 0x01 - 0x7F (never 0x00, remapped 0 to 1)
    }

    size_t getH1(size_t _hash) { return _hash >> 7; }

    static constexpr size_t GROUP_SIZE = 16;

    static constexpr uint8_t META_EMPTY = 0xFF;
    static constexpr uint8_t META_TOMBSTONE = 0x80;
    // META_OCCUPIED: 0x01 - 0x7F (H2 = hash & 0x7F, remapped 0 to 1)
  }
};
