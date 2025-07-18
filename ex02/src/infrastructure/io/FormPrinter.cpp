/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 15:35:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/FormPrinter.hpp"
#include "domain/models/form/AForm.hpp"
#include <iostream>

FormPrinter::FormPrinter() {}

FormPrinter::FormPrinter(const FormPrinter&) {}

FormPrinter& FormPrinter::operator=(const FormPrinter&) {
  throw std::runtime_error("Copying of FormPrinter is not allowed");
}

FormPrinter::~FormPrinter() {}

void FormPrinter::printForm(const AForm& aform) {
  std::cout << "Form, " << aform.getName()
     << ", Grade to Sign: " << aform.getGradeToSign()
     << ", Grade to Execute: " << aform.getGradeToExecute()
     << ", Status: " << (aform.isSigned() ? "Signed" : "Unsigned");
}
