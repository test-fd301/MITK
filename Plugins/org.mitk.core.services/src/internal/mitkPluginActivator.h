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

#ifndef MITKCORESERVICESPLUGIN_H_
#define MITKCORESERVICESPLUGIN_H_

#include <berryPlugin.h>
#include <berryIBundleContext.h>

#include "mitkIDataStorageService.h"
#include <mitkServiceEvent.h>

namespace mitk
{

class ModuleContext;

class org_mitk_core_services_Activator : public QObject, public ctkPluginActivator
{
  Q_OBJECT
  Q_INTERFACES(ctkPluginActivator)

public:
  
  static const std::string PLUGIN_ID;

  org_mitk_core_services_Activator();
  
  void start(ctkPluginContext* context);
  void stop(ctkPluginContext* context);

  void MitkServiceChanged(const mitk::ServiceEvent event);

private:

  mitk::IDataStorageService::Pointer dataStorageService;
  QMap<long, QObject*> mapMitkIdToAdapter;
  QMap<long, ctkServiceRegistration> mapMitkIdToRegistration;

  mitk::ModuleContext* mitkContext;
  ctkPluginContext* pluginContext;
  
  void AddMitkService(const mitk::ServiceReference &ref);

  ctkDictionary CreateServiceProperties(const mitk::ServiceReference& ref);
};

typedef org_mitk_core_services_Activator PluginActivator;

}

#endif /*MITKCORESERVICESPLUGIN_H_*/
