using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {


	// public member fields
	public GameObject camera;

	// public member methods
	public void Start () {
		
	}
	
	public void Update () {
		if (camera) {
			// camera.
			camera.transform.SetPositionAndRotation(transform.position, Quaternion.identity);
		}
	}

}
