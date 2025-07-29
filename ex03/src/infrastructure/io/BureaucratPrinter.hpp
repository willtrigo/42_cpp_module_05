/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratPrinter.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:17 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:02:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_PRINTER_HPP
#define BUREAUCRAT_PRINTER_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class BureaucratPrinter {
 public:
  static std::ostream& print(std::ostream& os, const Bureaucrat& bureaucrat);

 private:
  BureaucratPrinter(const BureaucratPrinter&);
  ~BureaucratPrinter();

  BureaucratPrinter& operator=(const BureaucratPrinter&);
};

#endif // BUREAUCRAT_PRINTER_HPP
