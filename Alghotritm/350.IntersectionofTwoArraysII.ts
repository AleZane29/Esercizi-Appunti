function intersect(nums1: number[], nums2: number[]): number[] {
	let res: number[] = [];
	for (let i = 0; i < nums1.length; i++) {
		for (let n = 0; n < nums2.length; n++) {
			if (nums1[i] == nums2[n]) {
				res.push(nums1[i]);
				nums1[i] = nums2[n] = -1;
				n = nums2.length;
			}
		}
	}
	return res;
}
