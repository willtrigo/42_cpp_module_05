/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratPrinter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:17:29 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 13:15:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/BureaucratPrinter.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

BureaucratPrinter::BureaucratPrinter(const BureaucratPrinter&) {}

BureaucratPrinter& BureaucratPrinter::operator=(const BureaucratPrinter&) {
  throw std::runtime_error("Copying of BureaucratPrinter is not allowed");
}

BureaucratPrinter::~BureaucratPrinter() {}

std::ostream& BureaucratPrinter::print(std::ostream& os, const Bureaucrat& bureaucrat) {
  return os << TerminalColor::getColor(BG_BLUE)
            << TerminalColor::getColor(WHITE)
            << bureaucrat.getName()
            << ", bureaucrat grade " << bureaucrat.getGrade() 
            << TerminalColor::getColor(RESET)
            << std::endl;
}
