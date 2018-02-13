using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {


	// public member fields
	public GameObject Camera;

	// private member fields
	private Rigidbody2D rb;
	private BoxCollider2D bc2d;
	private bool canJump = false;
	private bool lose = false;

	// public member methods
	public void Start() {
		rb = GetComponent<Rigidbody2D>();
		bc2d = GetComponent<BoxCollider2D>();
	}

	public void OnCollisionEnter2D(Collision2D coll) {
		if (coll.gameObject.tag == "Platform") {
			canJump = true;

			Vector3 contactPoint = coll.contacts[0].point;
			Vector3 center = bc2d.bounds.center;

		} else if (coll.gameObject.tag == "Spike"){
			lose = true;
		}
	}

	public void OnCollisionExit2D(Collision2D coll) {
		if (coll.gameObject.tag == "Platform") {
			canJump = false;
		} 
	}


	public void Update() {
		if (!lose) {
			if (Camera) {
				Vector3 pos = transform.position + new Vector3(0, 0, -10);
				Camera.transform.SetPositionAndRotation(pos, Quaternion.identity);
			}

			if ((Input.GetKey("w") || Input.GetKey("up")) && canJump) {
				rb.AddForce(new Vector2(0, 350));
				canJump = false;
			}

			if ((Input.GetKey("a") || Input.GetKey("left")) && Mathf.Abs(rb.velocity.x) < 6) {
				rb.AddForce(new Vector2(-500.0f * Time.deltaTime, 0));
			}
			if ((Input.GetKey("d") || Input.GetKey("right")) && Mathf.Abs(rb.velocity.x) < 6) {
				rb.AddForce(new Vector2(500.0f * Time.deltaTime, 0));
			}
			if (transform.position.y <= -20)
				lose = true;
		}
	}

}
