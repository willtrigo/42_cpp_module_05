/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratPrinter.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:02:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 17:38:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_PRINTER_HPP
#define BUREAUCRAT_PRINTER_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <iostream>

class BureaucratPrinter {
 public:
  static void print(std::ostream& os, const Bureaucrat& bureaucrat);

 private:
  BureaucratPrinter();
  BureaucratPrinter(const BureaucratPrinter&);
  BureaucratPrinter& operator=(const BureaucratPrinter&);
  ~BureaucratPrinter();
};

#endif // BUREAUCRAT_PRINTER_HPP
