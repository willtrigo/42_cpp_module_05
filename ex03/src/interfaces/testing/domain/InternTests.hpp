/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InternTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:40 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 18:54:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_TESTS_HPP
#define INTERN_TESTS_HPP

class InternTests {
 public:
  static void createTestSuite();

 private:
  InternTests(const InternTests&);
  ~InternTests();

  InternTests& operator=(const InternTests&);

  static void testValidForm();
  static void testInvalidForm();
};
#endif // INTERN_TESTS_HPP
