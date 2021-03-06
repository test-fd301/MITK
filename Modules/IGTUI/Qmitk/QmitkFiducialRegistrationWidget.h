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

#ifndef _QmitkFiducialRegistrationWidget_H_INCLUDED
#define _QmitkFiducialRegistrationWidget_H_INCLUDED

#include "ui_QmitkFiducialRegistrationWidget.h"
#include "QmitkStdMultiWidget.h"
#include "MitkIGTUIExports.h"
/*!
 * \brief IGT Fiducial Registration Widget
 *
 * Widget used to set fiducial landmarks in the image and to confirm the corresponding landmarks on the world object (patient/phantom).
 * 
 * SetImageFiducialsNode(), SetTrackerFiducialsNode() and SetMultiWidget() must be called, otherwise QmitkPointListWidget can not work. 
 * 
 * 
 *
 * \sa IGT
*/
class MitkIGTUI_EXPORT QmitkFiducialRegistrationWidget : public QWidget
{  
  Q_OBJECT // this is needed for all Qt objects that should have a MOC object (everything that derives from QObject)
public: 

  QmitkFiducialRegistrationWidget(QWidget* parent);
  virtual ~QmitkFiducialRegistrationWidget();

  /*!
  \brief enumeration to specify the appearance of the widget.
  'FIDUCIALMODE' is likely to be used for (tracking) fiducial based registration purposes
  'LANDMARKMODE' can be used for any kind of landmark based registration (source landmarks -> target/reference landmarks)
  */
  enum WidgetAppearanceMode
  {
    FIDUCIALMODE,
    LANDMARKMODE
  };
  /*!
  \brief set the appearance mode of this widget
  'FIDUCIALMODE' adapts the widget for (tracking) fiducial based registration purposes
  'LANDMARKMODE' adapts the widget for landmark based registration (source landmarks -> target/reference landmarks)
  */
  void SetWidgetAppearanceMode(WidgetAppearanceMode widgetMode);

  void SetMultiWidget(QmitkStdMultiWidget* multiWidget); ///< Set the default stdMultiWidget (needed for the PointListwidget)

  void SetImageFiducialsNode(mitk::DataNode::Pointer imageFiducialsNode); ///< specify data tree node for the image fiducials
  void SetTrackerFiducialsNode(mitk::DataNode::Pointer trackerFiducialsNode); ///< specify data tree node for the tracker fiducials  
  mitk::DataNode::Pointer GetImageFiducialsNode(); ///< returns data tree node for the image fiducials
  mitk::DataNode::Pointer GetTrackerFiducialsNode(); ///< returns data tree node for the tracker fiducials

  void SetQualityDisplayText(QString text); ///< sets specific text on the UI (useful to display FRE/TRE...)
  bool UseICPIsChecked(); ///< returns true if automatic correspondences search is activated else false
  void HideStaticRegistrationRadioButton(bool on); ///< show or hide  "static Fiducial Registration" radio button in the UI
  void HideContinousRegistrationRadioButton(bool on); ///< show or hide  "hybrid continuous Fiducial Registration" radio button in the UI
  void HideFiducialRegistrationGroupBox(); ///< show or hide  "Fiducial Registration method" groupbox in the UI, depending on the visibility of the radio buttons
  void HideUseICPRegistrationCheckbox(bool on); ///< show or hide  "Find fiducial correspondences (needs 6+ fiducial pairs)" check box in the UI
  void HideImageFiducialButton(bool on); ///< show or hide  "Add image fiducial" button in the UI
  void HideTrackingFiducialButton(bool on); ///< show or hide  "Add tracking fiducial" button in the UI
  void AdjustButtonSpacing(); ///< Rearrange spacing when buttons are turned on or off
  
  signals:
    void AddedTrackingFiducial();      ///< signal if a world instrument position was added to a tracking space fiducial
    void AddedImageFiducial();      ///< signal if an image position was added to a image space fiducial
    void PerformFiducialRegistration();        ///< signal if all fiducial were added and registration can be performed
    void FindFiducialCorrespondences(bool on); ///< signal if automatic correspondences search is toggled

  protected slots:
    void DisableEditButtonRegistrationImagePoints(bool);///< Disables the edit button of the widget RegistrationImagePoints if the activated variable is true.
    void DisableEditButtonRegistrationTrackingPoints(bool);///< Disables the edit button of the widget RegistrationTrackingPoints if the activated variable is true.

protected:

  void CreateQtPartControl(QWidget *parent);

  void CreateConnections();
  
  Ui::QmitkFiducialRegistrationWidget* m_Controls;  ///< gui widget
  QmitkStdMultiWidget* m_MultiWidget;
  mitk::DataNode::Pointer m_ImageFiducialsNode;
  mitk::DataNode::Pointer m_TrackerFiducialsNode;
 
};
#endif // _QmitkFiducialRegistrationWidget_H_INCLUDED
