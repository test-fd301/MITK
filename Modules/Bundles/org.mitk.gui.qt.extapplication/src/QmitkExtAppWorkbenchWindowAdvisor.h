/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef QMITKEXTAPPWORKBENCHWINDOWADVISOR_H_
#define QMITKEXTAPPWORKBENCHWINDOWADVISOR_H_

#include <cherryWorkbenchWindowAdvisor.h>

#include "mitkQtExtAppDll.h"

class MITK_QT_EXTAPP QmitkExtAppWorkbenchWindowAdvisor : public cherry::WorkbenchWindowAdvisor
{
public:

    QmitkExtAppWorkbenchWindowAdvisor(cherry::IWorkbenchWindowConfigurer::Pointer configurer);

    cherry::ActionBarAdvisor::Pointer CreateActionBarAdvisor(
        cherry::IActionBarConfigurer::Pointer configurer);

    void PostWindowCreate();
};

#endif /*QMITKEXTAPPWORKBENCHWINDOWADVISOR_H_*/
