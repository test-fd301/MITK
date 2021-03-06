/*===================================================================

BlueBerry Platform

Copyright (c) German Cancer Research Center, 
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR 
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/
#ifndef BERRYIPREFERENCESSERVICE_H_
#define BERRYIPREFERENCESSERVICE_H_

#include "service/berryService.h"
#include <org_blueberry_core_runtime_Export.h>
#include "berryIPreferences.h"

#include <vector>
#include <string>

#include <QtPlugin>

namespace berry 
{

  /**
   * The Preferences Service.
   * 
   * <p>
   * Each bundle using this service has its own set of preference trees: one for
   * system preferences, and one for each user.
   * 
   * <p>
   * A <code>PreferencesService</code> object is specific to the bundle which
   * obtained it from the service registry. If a bundle wishes to allow another
   * bundle to access its preferences, it should pass its
   * <code>PreferencesService</code> object to that bundle.
   *  
   */
  struct BERRY_RUNTIME IPreferencesService : public Service
  {
    ///
    /// A unique ID for the Service.
    ///
    static const std::string ID;

    berryInterfaceMacro(IPreferencesService, berry)

    /**
     * Returns the root system node for the calling bundle.
     * 
     * @return The root system node for the calling bundle.
     */
    virtual IPreferences::Pointer GetSystemPreferences() = 0;

    /**
     * Returns the root node for the specified user and the calling bundle.
     * 
     * @param name The user for which to return the preference root node. 
     * @return The root node for the specified user and the calling bundle.
     */
    virtual IPreferences::Pointer GetUserPreferences(std::string name) = 0;

    /**
     * Returns the names of users for which node trees exist.
     * 
     * @return The names of users for which node trees exist.
     */
    virtual std::vector<std::string> GetUsers() const = 0;
  };
}  // namespace berry

Q_DECLARE_INTERFACE(berry::IPreferencesService, "org.blueberry.service.IPreferencesService")

#endif /*BERRYIPREFERENCESSERVICE_H_*/
