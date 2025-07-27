/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratPrinter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 21:16:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/BureaucratPrinter.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

BureaucratPrinter::BureaucratPrinter(const BureaucratPrinter&) {}

BureaucratPrinter& BureaucratPrinter::operator=(const BureaucratPrinter&) {
  throw std::runtime_error("Copying of BureaucratPrinter is not allowed");
}

BureaucratPrinter::~BureaucratPrinter() {}

std::ostream& BureaucratPrinter::print(std::ostream& os, const Bureaucrat& bureaucrat) {
  return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}
