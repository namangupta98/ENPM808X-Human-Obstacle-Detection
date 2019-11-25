/******************************************************************************
 * MIT License

 * Copyright (c) 2019 Naman Gupta

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 ******************************************************************************/

/**
 * @file      MockDetectHumanTest.cpp
 * @author    Naman Gupta (namangupta98) Navigator
 * @copyright MIT License
 * @brief     Test cases for VisionInput class methods
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <MockDetectHuman.hpp>
#include <VisionInput.hpp>

TEST(CheckFile, FileExist) {
    MockDetectHuman* test = new MockDetectHuman();
    VisionInput vision;
    vision.fileExist(&test);
    EXPECT_CALL(*test, fileExist("../test_data/1.png"))
        .Times(::testing::AtLeast(1));

    EXPECT_TRUE(vision.fileExist("../test_data/1.png"));
    delete test;
}
