/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:16:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 15:16:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_TESTS_HPP
#define FORM_TESTS_HPP

class FormTests {
 public:
  static void createTestSuite();

 private:
  FormTests(const FormTests&);
  ~FormTests();

  FormTests& operator=(const FormTests&);

  static void testFormBasicFunctionality();
  static void testInvalidFormConstruction();
  static void testFormBoundaryConditions();
  static void testFormCopyOperations();
};

#endif // FORM_TESTS_HPP
