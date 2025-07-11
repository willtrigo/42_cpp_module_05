/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratPrinter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/11 20:49:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/BureaucratPrinter.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <iostream>

BureaucratPrinter::BureaucratPrinter() {}

BureaucratPrinter::BureaucratPrinter(const BureaucratPrinter& other) {
  (void)other;
}

BureaucratPrinter& BureaucratPrinter::operator=(const BureaucratPrinter& other) {
  (void)other;
  return *this;
}

BureaucratPrinter::~BureaucratPrinter() {}

void BureaucratPrinter::print(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
