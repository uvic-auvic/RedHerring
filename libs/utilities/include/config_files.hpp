/**************************************************************************
 * GPL LICENSE
/**************************************************************************
 *This file is part of the AUVIC Utilities Library.
 *
 * AUVIC Utilities is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *AUVIC Utilities is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with AUVIC Utilities.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************/

/**************************************************************************
 * Original Authors
/**************************************************************************
 *@package AUVIC Utilities
 *@file /includes/
 *@auth AUVic Software Team
 *@brief 
/**************************************************************************/

#ifndef AUVIC_CONFIG_FILES_H
#define AUVIC_CONFIG_FILES_H

/**************************************************************************
 * Include Headers
/**************************************************************************/
#include<string>
#include<map>

namespace AUVIC {

  class configs {
  public: // public member functions
    explicit configs (std::string);
    void add(std::string);
    const &std::unordered_map get_configs();
    int get_count();
    
    
  private:
    std::unordered_map configs
    int count;

  } //class

} //namespace

#endif //end of header guard
