/**********************************************************************
*  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
*  All rights reserved.
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#include "ModelSubTabView.hpp"
#include "OSItemSelector.hpp"
#include "OSItemSelectorButtons.hpp"
#include "ModelObjectInspectorView.hpp"
#include "ModelObjectListView.hpp"
#include "ModelObjectTypeListView.hpp"
#include "ModelObjectItem.hpp"
#include "OSAppBase.hpp"
#include "OSDocument.hpp"

#include "../model/Model.hpp"
#include "../model/Model_Impl.hpp"
#include "../utilities/core/Assert.hpp"

#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QButtonGroup>
#include <QResizeEvent>
#include <QTimer>
#include <QMouseEvent>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QRadioButton>

#include <iostream>

namespace openstudio {

ModelSubTabView::ModelSubTabView(OSItemSelector* itemSelector,
                       ModelObjectInspectorView* modelObjectInspectorView,
                       QWidget * parent)
  : SubTabView(itemSelector, modelObjectInspectorView, parent),
    m_modelObjectInspectorView(modelObjectInspectorView)
{
  connect(this, &ModelSubTabView::dropZoneItemClicked, this, &ModelSubTabView::dropZoneItemClicked);

  // DLM: can we remove this?
  connect(itemSelector, &OSItemSelector::itemSelected, this, &ModelSubTabView::onItemSelected);
}

// DLM: what purpose does this serve?
void ModelSubTabView::onItemSelected()
{
  boost::optional<model::ModelObject> mo;

  emit modelObjectSelected(mo,false);
}

ModelObjectInspectorView* ModelSubTabView::modelObjectInspectorView()
{
  return m_modelObjectInspectorView;
}

void ModelSubTabView::dropZoneItemClicked(OSItem* item)
{ 
  std::shared_ptr<OSDocument> currentDocument = OSAppBase::instance()->currentDocument();
  if (currentDocument){
    boost::optional<model::ModelObject> modelObject = currentDocument->getModelObject(item->itemId());
    bool readOnly = item->itemId().isDefaulted();
    emit modelObjectSelected(modelObject, readOnly);
  }
}

/*


void ModelSubTabView::addClicked()
{
  ModelObjectListView* modelObjectListView = qobject_cast<ModelObjectListView*>(m_itemSelector);
  if (modelObjectListView){
    IddObjectType iddObjectType = modelObjectListView->iddObjectType();
    emit addObjectClicked(iddObjectType);
  }

  ModelObjectTypeListView* modelObjectTypeListView = qobject_cast<ModelObjectTypeListView*>(m_itemSelector);
  if (modelObjectTypeListView){
    IddObjectType iddObjectType = modelObjectTypeListView->currentIddObjectType();
    emit addObjectClicked(iddObjectType);
  }
}

void ModelSubTabView::copyClicked()
{
  ModelObjectListView* modelObjectListView = qobject_cast<ModelObjectListView*>(m_itemSelector);
  if (modelObjectListView){
    boost::optional<openstudio::model::ModelObject> selectedModelObject = modelObjectListView->selectedModelObject();
    if (selectedModelObject){
      emit copyObjectClicked(*selectedModelObject);
    }
  }

  ModelObjectTypeListView* modelObjectTypeListView = qobject_cast<ModelObjectTypeListView*>(m_itemSelector);
  if (modelObjectTypeListView){
    boost::optional<openstudio::model::ModelObject> selectedModelObject = modelObjectTypeListView->selectedModelObject();
    if (selectedModelObject){
      emit copyObjectClicked(*selectedModelObject);
    }
  }

}

void ModelSubTabView::removeClicked()
{
  ModelObjectListView* modelObjectListView = qobject_cast<ModelObjectListView*>(m_itemSelector);
  if (modelObjectListView){
    boost::optional<openstudio::model::ModelObject> selectedModelObject = modelObjectListView->selectedModelObject();
    if (selectedModelObject){
      emit removeObjectClicked(*selectedModelObject);
    }
  }

  ModelObjectTypeListView* modelObjectTypeListView = qobject_cast<ModelObjectTypeListView*>(m_itemSelector);
  if (modelObjectTypeListView){
    boost::optional<openstudio::model::ModelObject> selectedModelObject = modelObjectTypeListView->selectedModelObject();
    if (selectedModelObject){
      emit removeObjectClicked(*selectedModelObject);
    }
  }

}

void ModelSubTabView::purgeClicked()
{
  ModelObjectListView* modelObjectListView = qobject_cast<ModelObjectListView*>(m_itemSelector);
  if (modelObjectListView){
    IddObjectType iddObjectType = modelObjectListView->iddObjectType();
    emit purgeObjectsClicked(iddObjectType);
  }

  ModelObjectTypeListView* modelObjectTypeListView = qobject_cast<ModelObjectTypeListView*>(m_itemSelector);
  if (modelObjectTypeListView){
    IddObjectType iddObjectType = modelObjectTypeListView->currentIddObjectType();
    emit purgeObjectsClicked(iddObjectType);
  }
}
*/

} // openstudio

