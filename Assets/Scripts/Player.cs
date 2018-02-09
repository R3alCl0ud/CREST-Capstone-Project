using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {


	// public member fields
	public GameObject Camera;

	// private member fields
	private Rigidbody2D rb;

	// public member methods
	public void Start() {
		rb = GetComponent<Rigidbody2D>();
	}
	
	public void Update() {
		if (Camera) {
			Vector3 pos = transform.position + new Vector3(0, 0, -10);
			Camera.transform.SetPositionAndRotation(pos, Quaternion.identity);
		}


		if (Input.GetKey("a") || Input.GetKey("left")) {
			Debug.Log("left");
			rb.AddForce(new Vector2(-500.0f * Time.deltaTime, 0));
		}
		if (Input.GetKey("d") || Input.GetKey("right")) {
			Debug.Log("right");
			rb.AddForce(new Vector2(500.0f * Time.deltaTime, 0));
		}
	}

}
