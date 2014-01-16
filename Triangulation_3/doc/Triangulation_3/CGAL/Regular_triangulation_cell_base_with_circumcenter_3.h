
namespace CGAL {

/*!
\ingroup PkgTriangulation3VertexCellClasses

The class `Regular_triangulation_cell_base_with_circumcenter_3` derives from 
`Cb`, a cell base class of a 3D triangulation.
It provides an easy way to cache the computation of the weighted circumcenters of 
tetrahedra. 
Note that input/output operators discard this additional information. 

All functions modifying the vertices of the cell invalidate the cached 
circumcenter. 

\tparam TriangulationTraits_3 is the geometric traits class. It should be a model
of `RegularTriangulationTraits_3`.

\tparam Cb is a cell base class from which 
`Regular_triangulation_cell_base_with_circumcenter_3` derives. Cb should
be a model of `RegularTriangulationCellBase_3`.
It has the default value `Triangulation_cell_base_3<RegularTriangulationTraits_3>`. 

\cgalModels `RegularTriangulationCellBase_3`

\sa `CGAL::Triangulation_cell_base_3` 
\sa `CGAL::Triangulation_cell_base_with_info_3` 
\sa `CGAL::Regular_triangulation_cell_base_3`

*/
template< typename TriangulationTraits_3, typename Cb >
class Regular_triangulation_cell_base_with_circumcenter_3 : public Cb {
public:
	
/// \name Types 
/// @{
typedef TriangulationTraits_3::Bare_point Bare_point;
/// @}

/// \name Access Functions 
/// @{

/*!
Computes the weighted circumcenter of the tetrahedron, or retrieves it if already 
computed.

The returned point has no weight.
*/ 
const Bare_point& weighted_circumcenter( 
	const TriangulationTraits_3&gt = TriangulationTraits_3()) const; 

/// @}

}; /* end Regular_triangulation_cell_base_with_circumcenter_3 */
} /* end namespace CGAL */
