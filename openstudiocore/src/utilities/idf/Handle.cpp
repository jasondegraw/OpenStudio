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

#include <utilities/idf/Handle.hpp>

#include <boost/foreach.hpp>

namespace openstudio {

Handle applyHandleMap(const Handle& original, const HandleMap& handleMap) {
  Handle result;
  HandleMap::const_iterator it = handleMap.find(original);
  if (it != handleMap.end()) {
    result = it->second;
  }
  return result;
}

HandleVector applyHandleMap(const HandleVector& original,const HandleMap& handleMap) {
  HandleVector result;
  BOOST_FOREACH(const Handle& oh,original) {
    HandleMap::const_iterator it = handleMap.find(oh);
    if (it != handleMap.end()) {
      result.push_back(it->second);
    }
  }
  return result;
}

}
