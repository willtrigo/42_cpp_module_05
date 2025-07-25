/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTests.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:16:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/24 23:08:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_TESTS_HPP
#define BUREAUCRAT_TESTS_HPP

class BureaucratTests {
 public:
  static void createTestSuite();

 private:
  BureaucratTests();
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
