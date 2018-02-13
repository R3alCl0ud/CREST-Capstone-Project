using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Platform : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	public void setLength(float length) {
		gameObject.transform.localScale = new Vector3(length, 0.5f, 1);
	}
}
