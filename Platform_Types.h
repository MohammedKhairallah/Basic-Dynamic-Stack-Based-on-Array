/* 
 * File:   Platform_Types.h
 * Author: Mohammed Khairallah
 * linkedin : linkedin.com/in/mohammed-khairallah
 * Created on December 27, 2023, 8:01 PM
 */
#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/*************************************/
#define CPU_TYPE (CPU_TYPE_64)
/*************************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;

#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;
typedef float float32_t;
typedef double float64_t;

#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef float float32_t;

#endif
/*************************************/
#endif // _PLATFORM_TYPES_H
