/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile: SampleAppMain.cpp,v $
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/ for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "SampleApp.h"
#include <qapplication.h>
#include "itkTextOutput.h"
#include <itksys/SystemTools.hxx>
#include <stdexcept>

#include <mitkStandardFileLocations.h>
#include <mitkProperties.h>
#include <mitkVector.h>

#include <QmitkFunctionalityTesting.h>
#include <sstream>

/*
* BUG: ATI-grafics-cards are slow in building up display lists in case of displaying transparent surfaces.
* Activating GlobalImmediateModeRendering in vtk solves this problem.
*/
//#include <vtkMapper.h>

#include <QmitkControlsRightFctLayoutTemplate.h>
#include <qsplitter.h>


int main(int argc, char* argv[])
{
  try
  {
    // Add directory in which the application executable resides as search directory
    mitk::StandardFileLocations::GetInstance()->AddDirectoryForSearch(itksys::SystemTools::GetFilenamePath(argv[0]).c_str()); 
    //
    // determine application name without path and extension
    //
    std::string executableName = itksys::SystemTools::GetFilenameWithoutExtension( itksys::SystemTools::GetFilenameName(argv[0] ) );
    std::stringstream caption;
    caption << executableName << ", Builddate " << __DATE__ << ", " << __TIME__ << ".";
    itk::OutputWindow::SetInstance(itk::TextOutput::New().GetPointer());
    // parse testing parameters
    bool enableFunctionalityTesting = false;
    const char * testingParameter = NULL;
    if (strcmp(argv[argc-1], "-testing")==0) {
      enableFunctionalityTesting = true;
    } else if (argc >= 2 && strcmp(argv[argc-2], "-testing")==0) {
      testingParameter = argv[argc-1];
      enableFunctionalityTesting = true;
    }

    QApplication a( argc, argv );
    SampleApp mainWindow(NULL, "mainwindow",Qt::WType_TopLevel,testingParameter);
    mainWindow.setCaption( caption.str().c_str() );
    a.setMainWidget(&mainWindow);
#ifdef USEDARKPALETTE
    std::cout << "changing palette ..." << std::endl;
    QPalette p( QColor( 64,64,64), QColor(64,64,64));
    a.setPalette(p,TRUE);
#endif
    /*
    * BUG: ATI-grafics-cards are slow in building up display lists in case of displaying transparent surfaces.
    * Activating GlobalImmediateModeRendering in vtk solves this problem. Also add #include vtkMapper above
    */
    //vtkMapper::GlobalImmediateModeRenderingOn();
         
    //B/     Setup MainApp Widget size (default: maximized) ////
    mitk::Point3dProperty* sizeProp = dynamic_cast<mitk::Point3dProperty*>
                                      (mainWindow.m_Options->GetProperty("Startup window size"));
    if(sizeProp)
    {
      mitk::Point3D p = sizeProp->GetValue();
      if(p[0] == 0.0 && p[1] == 0.0)
        mainWindow.showMaximized();
      else
      {
        mainWindow.resize(sizeProp->GetValue()[0], sizeProp->GetValue()[1]);      
        mainWindow.show();
      }
    }
    else
      mainWindow.showMaximized();

    mainWindow.RaiseDialogBars();

    //B/ Setup  MultiWidget size (default: 2/3 of total MainApp width) ////
    mitk::Point3dProperty* splitterSizeProp = dynamic_cast<mitk::Point3dProperty*>
                                      (mainWindow.m_Options->GetProperty("Main Splitter ratio"));

    QmitkControlsRightFctLayoutTemplate* fctwidget = (QmitkControlsRightFctLayoutTemplate*) mainWindow.centralWidget();
    if(fctwidget)
    {
      QValueList<int> i;

      if(splitterSizeProp)
      {
        mitk::Point3D p = splitterSizeProp->GetValue();
        if(p[0] == 0.0 && p[1] == 0.0)
        {
          i.push_back(mainWindow.width()/3*2);
          i.push_back(mainWindow.width()/3*1);
        }
        else
        {
          i.push_back(p[0]);
          i.push_back(p[1]);
        }
      }
      else
      {
        i.push_back(mainWindow.width()/3*2);
        i.push_back(mainWindow.width()/3*1);
      }
      fctwidget->MainSplitter->setSizes(i);
      mainWindow.repaint();
    }
    // reinit views after mainwindow and fctwidget initialization
    mainWindow.viewReinitMultiWidget();
    
    
    if(enableFunctionalityTesting) 
    {
      std::cout.setf(std::ios_base::unitbuf);
      return StartQmitkFunctionalityTesting(mainWindow.GetFctMediator());
    }
    else
    {
      return a.exec();
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << "MITK MainApp caught bad_alloc: Could not acquire enough memory: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch (const std::exception& e)
  {
    std::cout << "MITK MainApp caught an exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch (...)
  {
    std::cout << "MITK MainApp caught something like an exception..." << std::endl;
    return EXIT_FAILURE;
  }  
} 
