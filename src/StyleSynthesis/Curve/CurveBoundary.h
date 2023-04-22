//============================================================================
//
// This file is part of the Style Transfer project.
//
// Copyright (c) 2016
// -Zhaoliang Lun, Evangelos Kalogerakis (authors of the code) / UMass-Amherst
//
// This is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this software.  If not, see <http://www.gnu.org/licenses/>.
//
//============================================================================

#pragma once

#include <vector>
#include <string>

#include "Library/CMLHelper.h"

#include "Data/StyleSynthesisTypes.h"

using namespace std;

namespace StyleSynthesis {

	class CurveBoundary {

	public:

		CurveBoundary(TTriangleMesh &mesh);
		~CurveBoundary();

	public:

		bool extractCurve();
		bool output(vector<vector<vec3>> &curves);
		bool visualize(string fileName);

	private:

		bool extractBoundaryEdges();
		bool chainBoundaryEdges();

		static vec2i makeKey(int i1, int i2) { return i1 < i2 ? vec2i(i1, i2) : vec2i(i2, i1); }
		static vec2i makeKey(vec2i key) { return makeKey(key[0], key[1]); }

	private:

		TTriangleMesh *mpMesh;

		vector<vec2i> mBoundaryEdges;
		vector<vector<vec3>> mBoundaryChains;
	};
}