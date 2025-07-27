/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 13:08:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/FormPrinter.hpp"
#include "domain/models/form/AForm.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

FormPrinter::FormPrinter(const FormPrinter&) {}

FormPrinter& FormPrinter::operator=(const FormPrinter&) {
  throw std::runtime_error("Copying of FormPrinter is not allowed");
}

FormPrinter::~FormPrinter() {}

std::ostream& FormPrinter::print(std::ostream& os, const AForm& aform) {
  return os << TerminalColor::getColor(BG_YELLOW)
            << TerminalColor::getColor(BLACK)
            << aform.getName()
            << TerminalColor::getColor(RESET)
            << std::endl
            << TerminalColor::getColor(YELLOW)
            << "Grade to Sign: " << aform.getGradeToSign()
            << TerminalColor::getColor(RESET)
            << TerminalColor::getColor(YELLOW)
            << ", Grade to Execute: " << aform.getGradeToExecute()
            << TerminalColor::getColor(RESET)
            << TerminalColor::getColor(YELLOW)
            << ", Sign Status: " << (aform.isSigned() ? "Signed" : "Unsigned")
            << TerminalColor::getColor(RESET)
            << TerminalColor::getColor(YELLOW)
            << ", Execute Status: " << (aform.isExecuted() ? "Executed" : "Unexecuted")
            << TerminalColor::getColor(RESET)
            << std::endl;
}
