// Copyright (c) 2007  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Laurent Rineau

#ifndef CGAL_SURFACE_MESH_DEFAULT_EDGES_CRITERIA_3_H
#define CGAL_SURFACE_MESH_DEFAULT_EDGES_CRITERIA_3_H

#include <CGAL/Surface_mesher/Surface_mesher_edges_level.h>

namespace CGAL {

template <class Tr>
class Surface_mesh_default_edges_criteria_3
{
public:
  typedef typename Tr::Geom_traits GT;
  typedef typename GT::FT FT;
  typedef typename GT::Point_3 Point_3;

  typedef typename Tr::Edge Edge;
  typedef typename Tr::Vertex_handle Vertex_handle;

  Surface_mesh_default_edges_criteria_3(const FT radius_bound,
					const FT distance_bound)
    : sq_distance_bound(distance_bound*distance_bound),
      sq_radius_bound(FT(4)*radius_bound*radius_bound)
  {
  }

  bool is_bad (const Edge& e,
	       const Point_3& lineic_center) const
  {
    typename GT::Compute_squared_distance_3 sq_distance =
      GT().compute_squared_distance_3_object();

    const Vertex_handle& va = e.first->vertex(e.second);
    const Vertex_handle& vb = e.first->vertex(e.third);

    if(sq_radius_bound != FT(0) && 
       sq_distance(va->point(), vb->point()) > sq_radius_bound)
      return true;
    
    typename GT::Construct_midpoint_3 midpoint = 
      GT().construct_midpoint_3_object();

    return sq_distance_bound != FT(0) &&
      sq_distance(lineic_center, midpoint(va->point(), vb->point())) > 
      sq_distance_bound;
  }
private:
  FT sq_distance_bound;
  FT sq_radius_bound;
}; // end class Surface_mesh_default_edges_criteria_3

} // end namespace CGAL

#endif // CGAL_SURFACE_MESH_DEFAULT_EDGES_CRITERIA_3_H
