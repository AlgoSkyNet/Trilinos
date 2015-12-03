// @HEADER
// ***********************************************************************
//
//                 Anasazi: Block Eigensolvers Package
//                 Copyright (2004) Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
// USA
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ***********************************************************************
// @HEADER

#ifndef RBGEN_METHOD_FACTORY_HPP
#define RBGEN_METHOD_FACTORY_HPP

#include "Teuchos_ParameterList.hpp"
#include "RBGen_Method.hpp"

namespace RBGen {

  //! Abstract factory for creating basis generation methods.
  template< class DataSetType, class OperatorType > 
  class MethodFactory {

  public:
    //! @name Constructor/Destructor.
    //@{

    //! Default constructor.
    MethodFactory() {};

    //! Destructor.
    virtual ~MethodFactory() {};
    //@}

    //! @name Factory methods
    //@{

    virtual Teuchos::RCP<Method< DataSetType, OperatorType > > create( const Teuchos::ParameterList& params ) = 0;

    //@}

  };

} // end of RBGen namespace

#endif // RBGEN_METHOD_FACTORY_HPP