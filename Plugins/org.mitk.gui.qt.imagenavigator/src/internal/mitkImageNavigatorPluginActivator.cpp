/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center, 
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR 
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/
#include "mitkImageNavigatorPluginActivator.h"

#include "QmitkImageNavigatorView.h"

#include <QtPlugin>

namespace mitk {

  void ImageNavigatorPluginActivator::start(ctkPluginContext* context)
  {
    BERRY_REGISTER_EXTENSION_CLASS(QmitkImageNavigatorView, context)
  }

  void ImageNavigatorPluginActivator::stop(ctkPluginContext* context)
  {
    Q_UNUSED(context)
  }

}

Q_EXPORT_PLUGIN2(org_mitk_gui_qt_imagenavigator, mitk::ImageNavigatorPluginActivator)
