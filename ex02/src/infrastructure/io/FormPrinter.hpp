/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:02:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/11 22:08:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_PRINTER_HPP
#define FORM_PRINTER_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include <iostream>
#include <ostream>

class FormPrinter {
 public:
  static void print(std::ostream& os, const AForm& aform);
  static void printBeSigned(
    std::ostream& os, 
    const Bureaucrat& bureaucrat, 
    const AForm& aform);

 private:
  FormPrinter();
  FormPrinter(const FormPrinter& other);
  FormPrinter& operator=(const FormPrinter& other);
  ~FormPrinter();
};

#endif // FORM_PRINTER_HPP
