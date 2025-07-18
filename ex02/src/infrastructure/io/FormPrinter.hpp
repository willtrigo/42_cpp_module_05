/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormPrinter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:02:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 15:33:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_PRINTER_HPP
#define FORM_PRINTER_HPP

#include "domain/models/form/AForm.hpp"

class FormPrinter {
 public:
  static void printForm(const AForm& aform);

 private:
  FormPrinter();
  FormPrinter(const FormPrinter&);
  FormPrinter& operator=(const FormPrinter&);
  ~FormPrinter();
};

#endif // FORM_PRINTER_HPP
