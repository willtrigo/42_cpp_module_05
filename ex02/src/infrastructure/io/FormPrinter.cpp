/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/11 22:07:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/FormPrinter.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include <ostream>

FormPrinter::FormPrinter() {}

FormPrinter::FormPrinter(const FormPrinter& other) {
  (void)other;
}

FormPrinter& FormPrinter::operator=(const FormPrinter& other) {
  (void)other;
  return *this;
}

FormPrinter::~FormPrinter() {}

void FormPrinter::print(std::ostream& os, const AForm& aform) {
  os << "Form, " << aform.getName() << ", "
     << "Grade to Sign: " << aform.getGradeToSign() << ", "
     << "Grade to Execute: " << aform.getGradeToExecute() << ", "
     << "Status: " << (aform.isSigned() ? "Signed" : "Unsigned");
}

void FormPrinter::printBeSigned(
  std::ostream& os, 
  const Bureaucrat& bureaucrat,
  const AForm& aform) {
  os << "Bureaucrat " << bureaucrat.getName()
     << " signed form " << aform.getName() << std::endl;
}
