#include "ROL_ParList.hpp"

namespace ROL {

namespace detail {
template class PList<bool>;
template class PList<int>;
template class PList<double>;
template class PList<std::string>;
template class PList<std::vector<int>>;
template class PList<std::vector<double>>;
template class PList<std::vector<std::string>>;
} // namespace detail

ParList& 
ParList::sublist( ParList::key_type key, 
                  bool              mustAlreadyExist ) {
  if( !mustAlreadyExist ) 
    if( !sublists_.count(key) ) 
      sublists_[key] = std::make_unique<ParList>(1+get_level());
  
  return *(sublists_.at(key));
}

//std::ostream& operator << ( std::ostream& os, ParameterList& parlist ) {
//
//  detail::operator << ( os , parlist );
//
//  for( auto it=parlist.sublists_.begin(); it != parlist.sublists_.end(); ++it ) 
//    os << std::string(2*parlist.get_level(),' ') << 
//         it->first << ":\n" << *(it->second) << std::endl;
//  return os;
//}

} // namespace ROL



