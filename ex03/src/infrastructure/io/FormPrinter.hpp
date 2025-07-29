/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:02:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_PRINTER_HPP
#define FORM_PRINTER_HPP

#include "domain/models/form/AForm.hpp"
#include <iostream>
#include <ostream>

class FormPrinter {
 public:
  static std::ostream& print(std::ostream& os, const AForm& aform);

 private:
  FormPrinter(const FormPrinter&);
  ~FormPrinter();

  FormPrinter& operator=(const FormPrinter&);
};

#endif // FORM_PRINTER_HPP
