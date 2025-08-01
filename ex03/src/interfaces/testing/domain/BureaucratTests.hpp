/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTests.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:37:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:04:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_TESTS_HPP
#define BUREAUCRAT_TESTS_HPP

class BureaucratTests {
 public:
  static void createTestSuite();

 private:
  BureaucratTests(const BureaucratTests&);
  ~BureaucratTests();

  BureaucratTests& operator=(const BureaucratTests&);

  static void testBasicFuntionality();
  static void testGradeManipulation();
  static void testInvalidConstruction();
  static void testBoundaryConditions();
  static void testCopyOperations();
};

#endif // BUREAUCRAT_TESTS_HPP
