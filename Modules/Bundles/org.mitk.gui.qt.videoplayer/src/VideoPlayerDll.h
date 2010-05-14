/*=========================================================================
 
Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date: 2009-02-10 14:14:32 +0100 (Tue, 10 Feb 2009) $
Version:   $Revision: 14620 $
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#ifndef _VIDEOPLAYER_EXPORTS_DLL_H_
#define _VIDEOPLAYER_EXPORTS_DLL_H_

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the org_mitk_gui_qt_simpleexample_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// org_mitk_gui_qt_simpleexample_EXPORTS functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && !defined(MITK_STATIC)
  #if defined(org_mitk_gui_qt_simpleexample_EXPORTS)
    #define VIDEOPLAYER_EXPORTS __declspec(dllexport)
  #else
    #define VIDEOPLAYER_EXPORTS __declspec(dllimport)
  #endif
#endif


#if !defined(VIDEOPLAYER_EXPORTS)
  #define VIDEOPLAYER_EXPORTS
#endif

#endif /*_VIDEOPLAYER_EXPORTS_DLL_H_*/