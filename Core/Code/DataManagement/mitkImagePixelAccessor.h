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

#ifndef MITKIMAGEPIXELACCESSOR_H
#define MITKIMAGEPIXELACCESSOR_H

#include <algorithm>
#include <itkIndex.h>
#include <itkPoint.h>
#include <mitkCommon.h>
#include <itkSmartPointer.h>
#include "mitkImageAccessorBase.h"
#include "mitkImageDataItem.h"
#include "mitkPixelType.h"
#include "mitkImage.h"

namespace mitk {

class Image;


//##Documentation
//## @brief Provides templated image access for all inheriting classes
//## @tparam TPixel defines the PixelType
//## @tparam VDimension defines the dimension for accessing data
//## @ingroup Data
  template <class TPixel, unsigned int VDimension = 3>
  class ImagePixelAccessor
  {
    friend class Image;

  protected:
     /**  \param ImageDataItem* specifies the allocated image part */
    ImagePixelAccessor(mitk::Image::Pointer iP, mitk::ImageDataItem* iDI) :
      m_ImageDataItem(iDI)
    {
      if(iDI == NULL)
        m_ImageDataItem = iP->GetChannelData();
    }


    /** Destructor */
    virtual ~ImagePixelAccessor()
    {
    }

  protected:

    // protected members

    /** Holds the specified ImageDataItem */
    ImageDataItem* m_ImageDataItem;

    /** \brief Pointer to the used Geometry.
     *  Since Geometry can be different to the Image (if memory was forced to be coherent) it is necessary to store Geometry separately. */
    Geometry3D::Pointer m_Geometry;

    /** \brief A Subregion defines an arbitrary area within the image.
     *  If no SubRegion is defined, the whole ImageDataItem or Image is regarded.
     *  A subregion (e.g. subvolume) can lead to non-coherent memory access where every dimension has a start- and end-offset.
     */
    itk::ImageRegion<VDimension>* m_SubRegion;

    /** \brief Stores all extended properties of an ImageAccessor.
      * The different flags in mitk::ImageAccessorBase::Options can be unified by bitwise operations.
      */
    int m_Options;

  private:

  };

}

#endif // MITKIMAGEACCESSOR_H
