/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date: 2009-05-12 19:56:03 +0200 (Di, 12 Mai 2009) $
Version:   $Revision: 17179 $

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#include "mitkSurfaceToSurfaceFilter.h"
#include "mitkSurface.h"

mitk::SurfaceToSurfaceFilter::SurfaceToSurfaceFilter()
: SurfaceSource()
{
}

mitk::SurfaceToSurfaceFilter::~SurfaceToSurfaceFilter()
{
}


void mitk::SurfaceToSurfaceFilter::SetInput( const mitk::Surface* surface )
{
  this->SetInput( 0, const_cast<mitk::Surface*>( surface ) );
}


void mitk::SurfaceToSurfaceFilter::SetInput( unsigned int idx, const mitk::Surface* surface )
{
  if ( this->GetInput(idx) != surface )
  {
    this->SetNthInput( idx, const_cast<mitk::Surface*>( surface ) );
    this->CreateOutputsForAllInputs(idx);
    this->Modified();
  }
}


const mitk::Surface* mitk::SurfaceToSurfaceFilter::GetInput()
{
  if (this->GetNumberOfInputs() < 1)
    return NULL;

  return static_cast<const mitk::Surface*>(this->ProcessObject::GetInput(0));
}


const mitk::Surface* mitk::SurfaceToSurfaceFilter::GetInput( unsigned int idx)
{
  if (this->GetNumberOfInputs() < 1)
    return NULL;

  return static_cast<const mitk::Surface*>(this->ProcessObject::GetInput(idx));
}


void mitk::SurfaceToSurfaceFilter::CreateOutputsForAllInputs(unsigned int  /*idx*/)
{
  this->SetNumberOfOutputs( this->GetNumberOfInputs() );
  for (unsigned int idx = 0; idx < this->GetNumberOfOutputs(); ++idx)
    if (this->GetOutput(idx) == NULL)
    {
      DataObjectPointer newOutput = this->MakeOutput(idx);
      this->SetNthOutput(idx, newOutput);
    }
  this->Modified();
}


void mitk::SurfaceToSurfaceFilter::RemoveInputs(mitk::Surface* input)
{
  this->RemoveInput(input);
}