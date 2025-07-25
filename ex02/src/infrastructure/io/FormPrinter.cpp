/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 21:23:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/FormPrinter.hpp"
#include "domain/models/form/AForm.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

FormPrinter::FormPrinter(const FormPrinter&) {}

FormPrinter& FormPrinter::operator=(const FormPrinter&) {
  throw std::runtime_error("Copying of FormPrinter is not allowed");
}

FormPrinter::~FormPrinter() {}

std::ostream& FormPrinter::print(std::ostream& os, const AForm& aform) {
  return os << "Form, " << aform.getName()
            << ", Grade to Sign: " << aform.getGradeToSign()
            << ", Grade to Execute: " << aform.getGradeToExecute()
            << ", Sign Status: " << (aform.isSigned() ? "Signed" : "Unsigned")
            << ", Execute Status: " << (aform.isExecuted() ? "Executed" : "Unexecuted")
            << std::endl;
}
